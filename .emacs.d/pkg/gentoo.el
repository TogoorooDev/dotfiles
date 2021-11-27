;; Major modes for some portage files

(require 'imenu)

(defgroup use-mode ()
  "Options for use-mode"
  :group 'languages)

(defgroup use-mode-faces ()
  "Faces used by use-mode"
  :group 'use-mode)

;;(defface category-face
;;  '((t :inherit (font-lock-type-face)))
;;  "Face for atom categories"
;;  :group 'use-mode-faces)

(defface atom-face
  '((t :inherit (font-lock-variable-name-face)))X1
  "Face for package names"
  :group 'use-mode-faces)

(defface use-enabled-face
  '((t :inherit (font-lock-function-name-face)))
  "Face for enabled use flags"
  :group 'use-mode-faces)

(defface use-disabled-face
  '((t :inherit (font-lock-warning-face)))
  "Face for disabled use flags"
  :group 'use-mode-faces)

(setq use-highlights
      '(("^[a-zA-Z0-9,\-\/" . 'atom-face)
	("\ [^\-][a-zA-Z0-9,\-]" . 'use-enabled-face)
	("\ \-[a-zA-Z0-9,\-]" . 'use-disabled-face)))

(define-derived-mode use-mode fundamental-mode "use-mode"
  "major mode for editing Gentoo use flag files"
  (setq font-lock-defaults '(use-highlights)))
