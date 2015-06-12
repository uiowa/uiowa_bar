<?php
/**
 * @file
 *
 * Custom Search Results.
 */

$queryString = (drupal_get_query_parameters() ? drupal_get_query_parameters() : null);
$terms = check_plain($queryString['search']);
?>

<h3 id="university-search"><a href="http://search.uiowa.edu/search?q=<?php print $terms;?>&btnG=Search&client=our_frontend&output=xml_no_dtd&proxystylesheet=our_frontend&sort=date%3AD%3AL%3Ad1&entqr=0&oe=UTF-8&ie=UTF-8&ud=1&site=default_collection" target="_blank">Search the University of Iowa for <em><?php print $terms;?></em></a></h3>

<div id="search-results"></div>

<script>

var myCallback = function() {
  google.search.cse.element.render(
  {
      div: "search-results",
      tag: 'search',
      attributes:{
        queryParameterName:'search',
        <?php
          if(variable_get('uiowa_bar_cse_scope') == true){
            echo("as_sitesearch:'".$GLOBALS["base_url"]."',");
          }?>
      }
  });
};

window.__gcse = {
  parsetags: 'explicit',
  callback: myCallback
};

(function() {
  <?php echo("var cx = '".variable_get("uiowa_bar_cse_engine_id")."';"); ?>
  var gcse = document.createElement('script'); gcse.type = 'text/javascript';
  gcse.async = true;
  gcse.src = (document.location.protocol == 'https' ? 'https:' : 'http:') +
      '//www.google.com/cse/cse.js?cx=' + cx;
  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(gcse, s);
})();

</script>
