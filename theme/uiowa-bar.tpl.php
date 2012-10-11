<?php
/**
 * @file uiowa-bar.tpl.php
 *
 * This template handles the layout of the Uiowa Branding Bar.
 *
 * Variables available:
 *
 *
 */
?>

<?php

dpm($uiowa_bar, "UIowa Bar");
dpm(array_keys(theme_get_registry()));
?>

<div id="ui-wrapper">
  <div class="container">
    <?php print render($uiowa_bar); ?>
  </div>
</div><!--ui-wrapper and conatiner -->
