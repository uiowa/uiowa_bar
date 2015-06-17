/**
 * @file
 * UIowa bar CSE results functionality.
 */

(function ($) {
  Drupal.uiowaBarResults = function() {
    var cseAttributes = {
      queryParameterName: 'search',
    }

    if (Drupal.settings.uiowaBar.cseScope == 1) {
      cseAttributes.as_sitesearch = window.location.hostname;
    }

    google.search.cse.element.render({
        div: "search-results",
        tag: 'search',
        attributes: cseAttributes
    });
  };

  // Attach uiowaBarResults behavior.
  Drupal.behaviors.uiowaBarResults = {
    attach: function(context, settings) {
      $('#search-results', context).once('uiowaBarResults', function() {
        window.__gcse = {
          parsetags: 'explicit',
          callback: Drupal.uiowaBarResults,
        };

        (function() {
          var cx = Drupal.settings.uiowaBar.engineId;
          var gcse = document.createElement('script'); gcse.type = 'text/javascript';
          gcse.async = true;
          gcse.src = (document.location.protocol == 'https' ? 'https:' : 'http:') +
              '//www.google.com/cse/cse.js?cx=' + cx;
          var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(gcse, s);
        })();
      });
    }
  };
})(jQuery);
