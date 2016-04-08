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
  $items['answers_userpoints_voteup_answer_email'] = entity_import('rules_config', '{ "answers_userpoints_voteup_answer_email" : {
      "LABEL" : "voteup_answer_email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "myassist_notification", "voting_rules" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "answers_answer" : "answers_answer" } }
          }
        },
        { "data_is" : { "data" : [ "node:author:field-mail-on-voteup" ], "value" : "1" } }
      ],
      "DO" : [
        { "myassist_notification_rules_process" : {
            "recipient" : [ "node:author" ],
            "messageType" : "Du stemte p\\u00e5 et svar.",
            "node" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['myassist_questions_answers_create_answer_email'] = entity_import('rules_config', '{ "myassist_questions_answers_create_answer_email" : {
      "LABEL" : "create_answer_email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "rules", "myassist_notification" ],
      "ON" : { "node_insert--answers_answer" : { "bundle" : "answers_answer" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:author" ],
            "value" : [ "node:answers-related-question:author" ]
          }
        },
        { "data_is" : {
            "data" : [ "node:answers-related-question:author:field-mail-on-receive-assist" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "myassist_notification_rules_process" : {
            "recipient" : [ "node:answers-related-question:author" ],
            "messageType" : "question_answered",
            "node" : [ "node:answers-related-question" ]
          }
        }
      ]
    }
  }');
  $items['myassist_questions_answers_create_comment_email'] = entity_import('rules_config', '{ "myassist_questions_answers_create_comment_email" : {
      "LABEL" : "create_comment_email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "myassist_notification", "comment" ],
      "ON" : {
        "comment_insert--comment_node_answers_question" : { "bundle" : "comment_node_answers_question" },
        "comment_insert--comment_node_answers_answer" : { "bundle" : "comment_node_answers_answer" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "comment:node:author:field-mail-on-receive-comment" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "myassist_notification_rules_process" : {
            "recipient" : [ "comment:node:author" ],
            "messageType" : "comment_created",
            "node" : [ "comment:node" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_delete'] = entity_import('rules_config', '{ "rules_comment_delete" : {
      "LABEL" : "comment_delete",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "userpoints_rules", "comment" ],
      "ON" : {
        "comment_delete--comment_node_answers_question" : { "bundle" : "comment_node_answers_question" },
        "comment_delete--comment_node_answers_answer" : { "bundle" : "comment_node_answers_answer" }
      },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "comment:author" ],
            "points" : "-1",
            "tid" : "0",
            "entity" : [ "" ],
            "operation" : "Remove comment",
            "display" : "1",
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_create_answer'] = entity_import('rules_config', '{ "rules_create_answer" : {
      "LABEL" : "create_answer_points",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "myassist_notification" ],
      "ON" : { "node_insert--answers_answer" : { "bundle" : "answers_answer" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:author" ],
            "value" : [ "node:answers-related-question:author" ]
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "10",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Du har svaret p\\u00e5 et sp\\u00f8rgsm\\u00e5l.",
            "operation" : "Insert",
            "reference" : "Du har svaret p\\u00e5 et sp\\u00f8rgsm\\u00e5let [node:title].",
            "display" : "0",
            "moderate" : "default"
          }
        },
        { "myassist_notification_rules_process" : {
            "recipient" : [ "node:answers-related-question:author" ],
            "messageType" : "question_answered",
            "node" : [ "node:answers-related-question" ]
          }
        }
      ]
    }
  }');
  $items['rules_create_comment'] = entity_import('rules_config', '{ "rules_create_comment" : {
      "LABEL" : "create_comment_points",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "userpoints_rules", "comment" ],
      "ON" : {
        "comment_insert--comment_node_answers_question" : { "bundle" : "comment_node_answers_question" },
        "comment_insert--comment_node_answers_answer" : { "bundle" : "comment_node_answers_answer" }
      },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "comment:author" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "comment" ],
            "description" : "Du postede en kommentar.",
            "operation" : "Create comment",
            "display" : "1",
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
            "description" : "Du stillede et sp\\u00f8rgsm\\u00e5l.",
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
  $items['rules_flag_answers_best_answer_email'] = entity_import('rules_config', '{ "rules_flag_answers_best_answer_email" : {
      "LABEL" : "flag_answers_best_answer_email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "answers" ],
      "REQUIRES" : [ "rules", "myassist_notification", "flag" ],
      "ON" : { "flag_flagged_best_answer" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "flagging-user" ], "value" : [ "flagged-node:author" ] } },
        { "data_is" : {
            "data" : [ "flagged-node:author:field-mail-on-best-assist" ],
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "myassist_notification_rules_process" : {
            "recipient" : [ "flagged-node:author" ],
            "messageType" : "best_answer",
            "node" : [ "flagged-node" ]
          }
        }
      ]
    }
  }');
  $items['rules_lock_question'] = entity_import('rules_config', '{ "rules_lock_question" : {
      "LABEL" : "lock_question",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag" ],
      "ON" : { "flag_flagged_best_answer" : [] },
      "DO" : []
    }
  }');
  $items['rules_notify_advisor'] = entity_import('rules_config', '{ "rules_notify_advisor" : {
      "LABEL" : "Notify advisor on new question",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--answers_question" : { "bundle" : "answers_question" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:field-advisor:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-advisor:mail" ],
            "subject" : "[site:name] - En ung bruger beder om din assistance.",
            "message" : "[node:title]\\r\\n\\r\\n[node:url]\\r\\n",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "Tak fordi du oprettede et sp\\u00f8rgsm\\u00e5l. Vi har sendt en besked til [node:field-advisor:name]." } }
      ]
    }
  }');
  $items['rules_notify_on_question_from_parents'] = entity_import('rules_config', '{ "rules_notify_on_question_from_parents" : {
      "LABEL" : "Notify on question from parents",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "webform" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--webform" : { "bundle" : "webform" } },
      "IF" : [
        { "text_matches" : {
            "text" : [ "node:title" ],
            "match" : "Sp\\u00f8rgsm\\u00e5l fra for\\u00e6ldre"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "info@mitassist.dk",
            "subject" : "Sp\\u00f8rgsm\\u00e5l fra for\\u00e6ldre",
            "message" : "Nyt sp\\u00f8rgsm\\u00e5l fra for\\u00e6ldre\\r\\n[node:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_user_on_new_question_cloned_'] = entity_import('rules_config', '{ "rules_notify_user_on_new_question_cloned_" : {
      "LABEL" : "Notify users with unge profil on new question",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "notify" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--answers_question" : { "bundle" : "answers_question" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:body" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "nc@cyberhus.dk",
            "subject" : "[site:name] - En anden bruger har brug for et assist.",
            "message" : "Hey der\\r\\nEn anden bruger har oprettet et sp\\u00f8rgsm\\u00e5l...m\\u00e5ske er det dig der kender svaret?. \\r\\nKlik ind forbi og tjek sp\\u00f8rgsm\\u00e5let ud...og giv et assist.  \\r\\n\\r\\nMvh. Moderator-Teamet\\r\\n\\r\\nTitel p\\u00e5 sp\\u00f8rgsm\\u00e5l: [node:title]\\r\\n\\r\\nG\\u00e5 til sp\\u00f8rgsm\\u00e5l: [node:url]\\r\\n",
            "language" : [ "" ]
          }
        },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "8" : "8" } },
            "subject" : "[site:name] - En anden bruger har brug for et assist.",
            "message" : "Hey der\\r\\nEn anden bruger har oprettet et sp\\u00f8rgsm\\u00e5l...m\\u00e5ske er det dig der kender svaret?. \\r\\nKlik ind forbi og tjek sp\\u00f8rgsm\\u00e5let ud...og giv et assist.  \\r\\n\\r\\nMvh. Moderator-Teamet\\r\\n\\r\\nTitel p\\u00e5 sp\\u00f8rgsm\\u00e5l: [node:title]\\r\\n\\r\\nG\\u00e5 til sp\\u00f8rgsm\\u00e5l: [node:url]\\r\\n"
          }
        },
        { "drupal_message" : { "message" : "Tak fordi du oprettede et sp\\u00f8rgsm\\u00e5l. Vi har sendt en besked til [node:field-advisor:name]." } }
      ]
    }
  }');
  return $items;
}
