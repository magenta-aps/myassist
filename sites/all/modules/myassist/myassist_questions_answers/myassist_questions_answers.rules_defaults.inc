<?php
/**
 * @file
 * myassist_questions_answers.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function myassist_questions_answers_default_rules_configuration() {
  $items = array();
  $items['rules_create_answer'] = entity_import('rules_config', '{ "rules_create_answer" : {
      "LABEL" : "create_answer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "node_insert--answers_answer" : { "bundle" : "answers_answer" } },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "2",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Posted answer",
            "operation" : "Insert",
            "display" : "0",
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_create_question'] = entity_import('rules_config', '{ "rules_create_question" : {
      "LABEL" : "create_question",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "node_insert--answers_question" : { "bundle" : "answers_question" } },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "10",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Asked a question",
            "operation" : "Insert",
            "display" : "0",
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_delete_answer'] = entity_import('rules_config', '{ "rules_delete_answer" : {
      "LABEL" : "delete_answer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "node_delete--answers_answer" : { "bundle" : "answers_answer" } },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-2",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Removed answer",
            "operation" : "Remove",
            "display" : "0",
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_delete_question'] = entity_import('rules_config', '{ "rules_delete_question" : {
      "LABEL" : "delete_question",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "node_delete--answers_question" : { "bundle" : "answers_question" } },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-10",
            "tid" : "0",
            "entity" : [ "node" ],
            "operation" : "Remove",
            "reference" : "Question removed",
            "display" : "0",
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  return $items;
}
