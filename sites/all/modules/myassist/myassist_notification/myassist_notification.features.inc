<?php
/**
 * @file
 * myassist_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function myassist_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function myassist_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function myassist_notification_flag_default_flags() {
  $flags = array();
  // Exported flag: "Message read".
  $flags['message_read'] = array(
    'entity_type' => 'message',
    'title' => 'Message read',
    'global' => 0,
    'types' => array(
      0 => 'question_answered',
    ),
    'flag_short' => 'Mark as read',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark as unread',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Læst',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'message_notify_email_subject' => 0,
      'message_notify_email_body' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'myassist_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
