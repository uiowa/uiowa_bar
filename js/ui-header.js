(function ($) {
  Drupal.uiowa_bar = function() {
    // debulked onresize handler
    function on_resize(c,t){onresize=function(){clearTimeout(t);t=setTimeout(c,100)};return c};

    // toggle attribute function
    $.fn.toggleAttr = function(attr, attr1, attr2) {
      return this.each(function() {
        var self = $(this);
        if (self.attr(attr) == attr1)
          self.attr(attr, attr2);
        else
          self.attr(attr, attr1);
      });
    };

    // Set default states
    $("#ui-search-toggle").toggleClass("is-active is-inactive");
    $("#ui-search").addClass("animated").toggleClass("is-visible is-hidden");
    $('.osl-varient .division-directory').hide();

    // Evaluate on window resize
    on_resize(function() {
      // set aria-hidden for search toggle
      if ($('#ui-search-toggle').css('display') == 'none') {
        $("#ui-search-toggle").attr('aria-hidden', 'true');
      }
      else {
        $("#ui-search-toggle").attr('aria-hidden', 'false');
      }

      // set aria-hidden for search form
      if ($('#ui-search').css('display') == 'block') {
        $("#ui-search").attr('aria-hidden', 'false');
      }
      else {
        $("#ui-search").attr('aria-hidden', 'true');
      }
    })();

    // attach event listener to toggle
    $("#ui-search-toggle").click(function (evt) {
      evt.preventDefault();
      $(this).toggleClass("is-active is-inactive").toggleAttr('title', 'Open search bar', 'Close search bar');
      $('#ui-search').slideToggle().toggleClass("is-visible is-hidden").toggleAttr('aria-hidden', 'true', 'false');
    });

    $('.osl-varient .directory-toggle').click(function() {
        $(this).toggleClass("active");
        $('.division-directory').slideToggle();
        return false;
    });

    // For small screens - show the directory
    $('.division-menu').click(function() {
        $('.division-show-hide').slideToggle('slow');
        $('.division-menu .has-subnav a').toggleClass('active');

    });
  };

  // Attach uiowa_bar behavior.
  Drupal.behaviors.uiowa_bar = {
    attach: function(context, settings) {
      $('#ui-wrapper', context).once('uiowa_bar', function() {
        Drupal.uiowa_bar();
      });
    }
  };
})(jQuery);
