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

    if (Drupal.settings.uiowa_bar.uiowa_bar_link_style === 'uiowa-text') {
      $("#ui-global-bar-nav").before("<div id='ui-global-nav-sm'><a href='#'>Navigation</a></div>");
      $("#ui-global-links").hide().toggleClass("collapsed");
      $("#ui-global-nav-sm a").click(function (evt) {
        evt.preventDefault();
        $("#ui-global-links")
        .toggle()
        .toggleClass("expanded").toggleClass("collapsed");
        $("#ui-global-bar #gsa-search")
        .toggle()
        .toggleClass("expanded").toggleClass("collapsed");
      });
      $search = $("#ui-global-links li.last");
      $search.detach();
    }

    var mql700 = window.matchMedia("screen and (min-width: 700px)");

    /* If the search display is set to open for wide screen
    devices, then expand. */
    if (mql700.matches && Drupal.settings.uiowa_bar.uiowa_bar_search_display === 1) {
      $("#ui-global-bar #gsa-search").toggle().toggleClass("expanded");
    }

    var mql820 = window.matchMedia("screen and (min-width: 820px)");

    if (mql820.matches && Drupal.settings.uiowa_bar.uiowa_bar_link_style == "uiowa-text") {
      $("#ui-global-nav-sm").detach();
      $("#ui-global-links")
        .toggle()
        .toggleClass("expanded").toggleClass("collapsed");
      $("#ui-global-links ul").append($search);
    }

  });
}(jQuery));
