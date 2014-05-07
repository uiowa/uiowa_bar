<?php
$queryString = drupal_get_query_parameters();
?>

<h3 id="university-search"><a href="http://search.uiowa.edu/search?q=<?php echo $queryString['search'];?>" target="_blank">Search the University of Iowa for <em><?php echo $queryString['search'];?></em></a></h3>

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
            echo('as_sitesearch:'.$GLOBALS["base_url"].','); 
          }?>
        
      }
  });
};


</script>