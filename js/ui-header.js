(function ($) {
   $(document).ready(function() {
	   // Use uniform.js library to customize select box in ui-header
	   $("#ui-global-bar select").uniform();
	   
	   $("#ui-global-bar #search-box").hide().toggleClass("collapsed"); 
	   $("#ui-global-bar a.search").click(function (evt) { 
		  evt.preventDefault();
		  
		  
		  $("#ui-global-bar #search-box").toggle();
		  $(this).toggleClass("expanded"); 
	   });
   });
}(jQuery));