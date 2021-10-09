;; Packages
(require 'package)
(require 'semantic)
(require 'semantic/ia)
(require 'company)
(require 'ggtags)

;; Remove X11 cruft
(menu-bar-mode -1)
(toggle-scroll-bar -1)
(tool-bar-mode -1)

;; Package Setup
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/") t)
(package-initialize)

;; Theme
(load-theme 'wombat)
(global-display-line-numbers-mode)

;; Language Support


;;; CEDET
(semantic-add-system-include "/usr/include" 'c-mode)
(semantic-add-system-include "/usr/local/include" 'c-mode)
(global-semanticdb-minor-mode 1)
(global-semantic-highlight-func-mode 1)
(global-semantic-idle-scheduler-mode 1)
(semantic-mode 1)

;; Personal info
(setq user-mail-address "hens25252@protonmail.com")
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages '(crystal-mode company ## lsp-mode go-autocomplete go-mode))
 '(semantic-mode t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
