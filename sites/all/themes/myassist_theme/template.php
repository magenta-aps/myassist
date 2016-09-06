<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function myassist_theme_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  myassist_theme_preprocess_html($variables, $hook);
  myassist_theme_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function myassist_theme_preprocess_html(&$variables, $hook) {
  // Add Facebook Pixel tracking code on all pages
  $fb_markup = '<noscript><img height="1" width="1" style="display:none" src="https://www.facebook.com/tr?id=686677638133594&ev=PageView&noscript=1"/></noscript>';
  $fb_pixel = array(
    '#type' => 'markup',
    '#markup' => $fb_markup,
  );
  drupal_add_html_head($fb_pixel, 'fb_pixel');
  drupal_add_js(drupal_get_path('theme', 'myassist_theme') . '/js/facebook_pixel_code.js');
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/*
function myassist_theme_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
  dpm($variables, $hook);
  //drupal_add_js(  );
}
*/

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function myassist_theme_preprocess_node(&$variables, $hook) {
  // Add GA conversion JS by node ID of the welcome page after user registration
  if (current_path() == 'node/561') {
    drupal_add_js(drupal_get_path('theme', 'myassist_theme') . '/js/GA_user_registration_conversion.js');
    drupal_add_js('http://www.googleadservices.com/pagead/conversion.js', 'external');
  }

  $node = $variables['node'];
  $variables['date'] = format_date($node->created, 'short');
  if (variable_get('node_submitted_' . $node->type, TRUE)) {
    $variables['submitted'] = t('Submitted by !username !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
  }
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function myassist_theme_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function myassist_theme_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function myassist_theme_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Fix broken Drupal function that sets the item if it doesn't exist
 * hide($array['nonexisting']) will create the 'nonexisting' entry in the $array object, making checks for its existence unexpectedly pass
 * graceful_hide($array['nonexisting']) does not create a new entry in the $array object
 *
 * Me: Whyyyyy?
 * Drupal: Because Fuck You, that's why
 *
 * @param $item
 *   A renderable object that may or may not exist
 */
function graceful_hide(&$item) {
  if (isset($item)) {
    hide($item);
  }
}

/*
 * Implements hook_more_link().
 */
function myassist_theme_more_link($variables) {
  if ($variables['url'] == 'blog') { // Not pretty, but gets the job done
    return '<div class="more-link">' . l(t('Alle blogindlæg'), $variables['url'], array('attributes' => array('title' => $variables['title']))) . '</div>';
  }
  return theme_more_link($variables);
}
