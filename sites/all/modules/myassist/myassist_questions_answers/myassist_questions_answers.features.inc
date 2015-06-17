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

/**
 * Implements hook_default_message_type().
 */
function myassist_questions_answers_default_message_type() {
  $items = array();
  $items['best_answer'] = entity_import('message_type', '{
    "name" : "best_answer",
    "description" : "Best answer",
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
          "value" : "\u003Ca href=\u0022[site:url]node\/[message:field-node:nid]\u0022\u003EDit svar\u003C\/a\u003E p\u00e5 sp\u00f8rgsm\u00e5let \u003Ca href=\u0022[site:url]node\/[message:field-node:answers-related-question:nid]\u0022\u003E[message:field-node:answers-related-question:title]\u003C\/a\u003E er blevet udvalgt som sp\u00f8rgsm\u00e5lets bedste svar.",
          "format" : "full_html",
          "safe_value" : "\u003Cp\u003E\u003Ca href=\u0022[site:url]node\/[message:field-node:nid]\u0022\u003EDit svar\u003C\/a\u003E p\u00e5 sp\u00f8rgsm\u00e5let \u003Ca href=\u0022[site:url]node\/[message:field-node:answers-related-question:nid]\u0022\u003E[message:field-node:answers-related-question:title]\u003C\/a\u003E er blevet udvalgt som sp\u00f8rgsm\u00e5lets bedste svar.\u003C\/p\u003E\n"
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
