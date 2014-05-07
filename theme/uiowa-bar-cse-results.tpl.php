<?php
$queryString = drupal_get_query_parameters();
?>

<h3 id="university-search"><a href="http://search.uiowa.edu/search?q=<?php echo $queryString['search'];?>" target="_blank">Search the University of Iowa for <em><?php echo $queryString['search'];?></em></a></h3>

<div id="search-results"></div>
