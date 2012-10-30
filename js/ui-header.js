(function ($) {
  $(document).ready(function() {
    // Use uniform.js library to customize select box in ui-header
    $("#ui-global-bar select").uniform();
    $("#ui-global-bar #gsa-search").hide().toggleClass("collapsed");
    $("#ui-global-bar a.search").click(function (evt) {
      evt.preventDefault();
      $("#ui-global-bar #gsa-search")
      //.css('height', '28px')
      //.css('overflow', 'hidden')
      .toggle()
      .toggleClass("expanded").toggleClass("collapsed");
    });

    var mql700 = window.matchMedia("screen and (min-width: 700px)");

    /* If the search display is set to open for wide screen
    devices, then expand. */
    if (mql700.matches && Drupal.settings.uiowa_bar.uiowa_bar_search_display === 1) {
      $("#ui-global-bar #gsa-search").toggle().toggleClass("expanded");
    }

    var mql820 = window.matchMedia("screen and (min-width: 820px)");
  });
}(jQuery));
