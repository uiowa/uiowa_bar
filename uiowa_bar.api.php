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
function HOOK_uiowa_bar_top_alter(&$uiowa_bar) {
  // No example.
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
function HOOK_uiowa_bar_footer_alter(&$uiowa_bar) {
  // No example.
}
