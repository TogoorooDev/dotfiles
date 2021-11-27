Dark CSS theme
==============

Description
-----------

Put the file in ~/.surf/styles/default.css to get a dark themed surf. It uses
the same CSS as vimb's dark mode.

It makes everything dark gray and makes images opacity lower unless you hover over them.

    *,div,pre,textarea,body,input,td,tr,p {
        background-color: #202020 !important;
        background-image: none !important;
        color: #bbbbbb !important;
    }
    h1,h2,h3,h4 {
        background-color: #202020 !important;
        color: #b8ddea !important;
    }
    img {
        opacity: .5;
    }
    img:hover {
        opacity: 1;
    }
