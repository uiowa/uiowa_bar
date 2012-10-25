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
   });
}(jQuery));
