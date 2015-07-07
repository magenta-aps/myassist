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
    "message_text" : { "da" : [
        {
          "value" : "\\u003Cp\\u003EDu har f\\u00e5et et assist! - MitAssist.dk\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EDu har f\\u00e5et et assist! - MitAssist.dk\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EHej, Du har f\\u00e5et et nyt assist p\\u00e5 dit sp\\u00f8rgsm\\u00e5l: \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EHej, Du har f\\u00e5et et nyt assist p\\u00e5 dit sp\\u00f8rgsm\\u00e5l: \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
