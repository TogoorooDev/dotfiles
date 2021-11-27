(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
;;(add-to-list 'package-archives '("gnu" . "
(package-initialize)

(eval-when-compile
  (require 'use-package))'

(setq backup-directory-alist
      '(("~" . ".local/share/emcas/saves")))

(setq backup-by-copying t
      kept-old-versions 5
      kept-new-versions 2
      )

;;setq auto-save-list-file-prefix
  ;;  (concat "~/.local/share/emacs/saves/auto-saves")

(defun ui-general-hook (frame)
  (with-selected-frame frame  
    (menu-bar-mode -1)
    (toggle-scroll-bar -1)
    (tool-bar-mode -1)
    (load-theme 'wombat)
    (global-display-line-numbers-mode)
    )
)

(use-package dashboard
  :config
  (dashboard-setup-startup-hook)
  (setq initial-buffer-choice (lambda () (get-buffer "*dashboard*"))))

(add-hook 'after-make-frame-functions 'ui-general-hook)



(global-company-mode)

(defun luna-web-mode-hook ()
  "Luna web mode hook"
  ;; indent
  (setq web-mode-markup-indent-offset 2)
  (setq web-mode-code-indent-offset 2)
  (setq web-mode-css-indent-offset 2)

  ;; company
  (set (make-local-variable 'company-backends) '(company-css company-web-html company-yasnippet company-files))
  
)

(add-to-list 'auto-mode-alist '("\\.ts\\'" . web-mode))
(add-to-list 'auto-mode-alist '("\\.js\\'" . web-mode))
(add-to-list 'auto-mode-alist '("\\.html\\'" . web-mode))
(add-to-list 'auto-mode-alist '("\\.htm\\'" . web-mode))
(add-to-list 'auto-mode-alist '("\\.css\\'" . web-mode))

(setq web-mode-enable-current-column-highlight t)
(setq web-mode-enable-current-element-highlight t)

(add-hook 'web-mode-before-auto-complete-hooks
    '(lambda ()
     (let ((web-mode-cur-language
	    (web-mode-language-at-pos)))
	       (if (string= web-mode-cur-language "php")
	   (yas-activate-extra-mode 'php-mode)
	 (yas-deactivate-extra-mode 'php-mode))
	       (if (string= web-mode-cur-language "css")
	   (setq emmet-use-css-transform t)
	 (setq emmet-use-css-transform nil)))))

(setenv "GOPATH" "/home/hens/go/bin")
(setenv "PATH" (concat (getenv "PATH") ":" (concat (getenv "GOPATH"))))

(defun go-mode-config ()
    (go-eldoc-setup)
    (add-hook 'before-save-hook 'gofmt-before-save)
    (setq gofmt-command "goimports")
  )

(add-hook 'go-mode-hook 'go-mode-config)

(global-set-key (kbd "C-c C-c") 'comment-or-uncomment-region)

(define-key global-map (kbd "M-t") nil)

(global-set-key (kbd "M-t M-j") 'tab-bar-switch-to-prev-tab)
(global-set-key (kbd "M-t M-k") 'tab-bar-switch-to-next-tab)
(global-set-key (kbd "M-t M-n") 'tab-bar-new-tab)
(global-set-key (kbd "M-t M-w") 'tab-bar-close-tab)
(global-set-key (kbd "M-t M-l") 'tab-bar-move-tab) 
(global-set-key (kbd "M-t M-t") 'tab-bar-mode)

(add-hook 'go-mode-hook '(lambda ()
			   (local-set-key (kbd "C-c C-r") 'go-remove-unused-imports)))

(add-hook 'go-mode-hook '(lambda ()
			   (local-set-key (kbd "C-c C-g") 'go-goto-imports)))

(add-hook 'go-mode-hook '(lambda ()
			   (local-set-key (kbd "C-c C-f") 'go-fmt)))
