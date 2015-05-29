<?php

/**
 * @file
 * API documentation for uiowa_bar.
 */

/**
 * Alter the top branding bar before being built.
 *
 * Allow modules to alter the top uiowa bar render array just before being
 * passed to hook_page_build().
 *
 * @param array $uiowa_bar
 *   The top render array.
 *
 * @see: build_uiowa_bar().
 */
function hook_uiowa_bar_top_alter(&$uiowa_bar) {
  // Add some arts-related links. Used on http://arts.uiowa.edu.
  $items = array(
    'support' => array(
      'data' => l(t('Support the Arts'), 'http://www.uifoundation.org/artscampaign/', array('attributes' => array('class' => 'support-link'))),
    ),
    'campus' => array(
      'data' => l(t('Public Art on Campus'), 'http://www.facilities.uiowa.edu/art-on-campus/', array('attributes' => array('class' => 'campus-link'))),
    ),
  );
  $uiowa_bar['ui-global-bar']['container']['ai-links'] = array(
    '#attributes' => array('class' => array('ai-links')),
    '#theme' => 'item_list',
    '#items' => $items,
  );
}

/**
 * Alter the branding footer before being built.
 *
 * Allow modules to alter the bottom uiowa bar render array just before being
 * passed to hook_page_build().
 *
 * @param array $uiowa_bar
 *   The footer render array.
 *
 * @see: build_uiowa_bar_footer().
 */
function hook_uiowa_bar_footer_alter(&$uiowa_bar) {
  // Provide a login link for anonymous users. Used on http://ideal.uiowa.edu/
  global $base_url;
  if (!user_is_logged_in()) {
    $uiowa_bar['ui-global-footer']['container']['hawkid-login'] = array(
      '#attributes' => array('id' => array('hawkid-login')),
      '#type' => 'container',
    );
    $uiowa_bar['ui-global-footer']['container']['hawkid-login']['link'] = array(
      '#markup' => '<a href="' . $base_url . '/cas?destination=front">Login</a>',
    );
  }
}
