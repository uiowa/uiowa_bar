(function ($) {
  Drupal.uiowa_bar = function() {
    $("#ui-search-toggle").addClass("inactive");
    $("#ui-search").addClass("search-hidden");

    $("#ui-search-toggle").click(function (evt) {
      evt.preventDefault();

      if ($(this).hasClass('inactive')) {
        $(this).addClass('active').removeClass('inactive');
        $('#ui-search').addClass('search-exposed').removeClass('search-hidden');
      } else if ($(this).hasClass('active')) {
        $(this).addClass('inactive').removeClass('active');
        $('#ui-search').addClass('search-hidden').removeClass('search-exposed');
      }

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
