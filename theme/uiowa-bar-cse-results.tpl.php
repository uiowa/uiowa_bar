
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
          if(variable_get('uiowa_bar_cse_scope') == true){ ?>
            as_sitesearch:'<?=$GLOBALS["base_url"]?>',
          <?}?>
        
      }
  });
};
window.__gcse = {
  parsetags: 'explicit',
  callback: myCallback
};

(function() {
  var cx = '<?=variable_get("uiowa_bar_cse_engine_id")?>'; // Insert your own Custom Search engine ID here
  var gcse = document.createElement('script'); gcse.type = 'text/javascript';
  gcse.async = true;
  gcse.src = (document.location.protocol == 'https' ? 'https:' : 'http:') +
      '//www.google.com/cse/cse.js?cx=' + cx;
  var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(gcse, s);
})();
    

</script>