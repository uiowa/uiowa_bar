/**
 * @file
 * UIowa bar CSE results functionality.
 */

(function ($, Drupal, drupalSettings) {

  'use strict';

  Drupal.uiowaBarResults = function() {
    var cseAttributes = {
      queryParameterName: 'search',
    }

    if (drupalSettings.uiowaBar.cseScope == 1) {
      cseAttributes.as_sitesearch = window.location.hostname+drupalSettings.path.baseUrl;
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
      window.__gcse = {
        parsetags: 'explicit',
        callback: Drupal.uiowaBarResults,
      };
      var cx = drupalSettings.uiowaBar.engineId;
      var gcse = document.createElement('script'); gcse.type = 'text/javascript';
      gcse.async = true;
      gcse.src = 'https://cse.google.com/cse.js?cx=' + cx;
      var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(gcse, s);
    }
  };
})(jQuery, Drupal, drupalSettings);
