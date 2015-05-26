<?php
/**
 * @file
 * myassist_questions_answers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function myassist_questions_answers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function myassist_questions_answers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
