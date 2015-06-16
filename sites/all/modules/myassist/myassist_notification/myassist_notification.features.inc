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
    'api_version' => 3,
    'module' => 'myassist_notification',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function myassist_notification_default_message_type() {
  $items = array();
  $items['question_answered'] = entity_import('message_type', '{
    "name" : "question_answered",
    "description" : "Answer created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "da",
    "arguments" : null,
    "message_text" : {
      "da" : [
        {
          "value" : "Der er kommet et nyt svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022[site:url]node\\/[message:field-node:nid]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDer er kommet et nyt svar til sp\\u00f8rgsm\\u00e5let: \\u003Ca href=\\u0022[site:url]node\\/[message:field-node:nid]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \\u003Ca href=\\u0022\\/node\\/[message:field-message-node-reference:nid]\\u0022\\u003E[message:field-message-node-reference:field_description]\\u003C\\/a\\u003E",
          "format" : "html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
