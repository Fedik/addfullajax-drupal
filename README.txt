Module connect FullAJAX (https://github.com/Fedik/FullAJAX) library
to Drupal that allow use AJAX/AHAH technology on the Drupal sites
without advanced knowledges.

Fullajax = AJAX (Asynchronous JavaScript and XML)
+ AHAH (Asynchronous HTML and HTTP)

Thing that make your site "full AJAX'd" - means that the site pages will
be updated partially without full page reloading.

Installation and configuration:
- install libraries module
- download FullAJAX library from https://github.com/Fedik/FullAJAX
and put it in to /sites/all/libraries/fullajax/fullajax.js
- install and enable Add FullAJAX module
- go to module configuration and enter there the right CSS content id
from you real template, and set position where displayed
the main content, it important for right content rendering
- got to front page and check, now you have the full AJAX'd site ;)

Note for the default drupal template "bartik":
  Enable "Aggregate and compress CSS files"
  or use the option "seal:true" in FullAJAX configuration
  (just find FLAX.Filter.add({url:'/', id:addFullAjaxId});
  and change to FLAX.Filter.add({url:'/', id:addFullAjaxId, seal: true}); ).
  It need for fix the css conflicts that can happen in this template
  after request

How it works:
 FullAJAX library will wrap all links and forms on site,
 that matched defined filter(s) and after click on it will do request
 on server, where the current module will render the answer based
 on request and module settings.

More advanced:
- you can disable this module for some themes, recommend disable for
the admin theme
- you can enable block update, because basically updates only content
- you can ignore some links using FLAX.Filter:
http://getsite.org.ua/en/fullajax/basics-usage-fullajax-library
- more on: https://github.com/Fedik/FullAJAX
and http://getsite.org.ua/en/category/fullajax
