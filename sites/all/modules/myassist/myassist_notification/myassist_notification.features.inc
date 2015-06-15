<?php
/**
 * @file
 * myassist_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function myassist_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
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
          "value" : "Der er kommet et nyt svar til sp\u00f8rgsm\u00e5let: \u003Ca href=\u0022[site:url]node\/[message:field-node:nid]\u0022\u003E[message:field-node:title]\u003C\/a\u003E",
          "format" : "plain_text",
          "safe_value" : "\u003Cp\u003EDer er kommet et nyt svar til sp\u00f8rgsm\u00e5let: \u0026lt;a href=\u0026quot;[site:url]node\/[message:field-node:nid]\u0026quot;\u0026gt;[message:field-node:title]\u0026lt;\/a\u0026gt;\u003C\/p\u003E\n"
        }
      ],
      "en" : [
        {
          "value" : "There is a new reply to the question: \u003Ca href=\u0022\/node\/[message:field-message-node-reference:nid]\u0022\u003E[message:field-message-node-reference:field_description]\u003C\/a\u003E",
          "format" : "html"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
