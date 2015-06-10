<?php
/**
 * @file
 * myassist_questions_answers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function myassist_questions_answers_views_default_views() {
  $export = array();

    $view = new view();
    $view->name = 'question_answers';
    $view->description = 'Provide a list of answers to a question';
    $view->tag = 'answers, answers_best_answer, answers_voting';
    $view->base_table = 'node';
    $view->human_name = 'Answers to a Question';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'mere';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
    $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
    $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
    $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '40';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['view_mode'] = 'full';
    /* Overskrift: Global: Antal svar */
    $handler->display->display_options['header']['answers_count']['id'] = 'answers_count';
    $handler->display->display_options['header']['answers_count']['table'] = 'views';
    $handler->display->display_options['header']['answers_count']['field'] = 'answers_count';
    /* Relationship: Flag: best_answer */
    $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
    $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
    $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
    $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag_best_answer';
    $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
    $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'best_answer';
    $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
    /* Relationship: Indhold: Vote results */
    $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
    $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
    $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
    $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Afstemningsresultater';
    $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
            'value_type' => 'points',
            'tag' => '',
            'function' => 'sum',
    );
    /* Sort criterion: Flag: Flagtidspunkt */
    $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
    $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
    $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
    $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
    $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Flagtidspunkt';
    /* Sort criterion: Afstemningsresultater: Værdi */
    $handler->display->display_options['sorts']['value']['id'] = 'value';
    $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
    $handler->display->display_options['sorts']['value']['field'] = 'value';
    $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
    $handler->display->display_options['sorts']['value']['order'] = 'DESC';
    $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
    $handler->display->display_options['sorts']['value']['expose']['label'] = 'Bedste svar først';
    $handler->display->display_options['sorts']['value']['coalesce'] = 1;
    /* Sort criterion: Indhold: Oprettelsesdato */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
    $handler->display->display_options['sorts']['created']['expose']['label'] = 'Nyeste svar først';
    /* Contextual filter: Indhold: Related Question (answers_related_question) */
    $handler->display->display_options['arguments']['answers_related_question_target_id']['id'] = 'answers_related_question_target_id';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['table'] = 'field_data_answers_related_question';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['field'] = 'answers_related_question_target_id';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['answers_related_question_target_id']['summary_options']['items_per_page'] = '25';
    /* Filter criterion: Indhold: Udgivet */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Indhold: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
            'answers_answer' => 'answers_answer',
    );
    $translatables['question_answers'] = array(
            t('Master'),
            t('mere'),
            t('Udfør'),
            t('Gendan'),
            t('Sortér efter'),
            t('Stigende'),
            t('Faldende'),
            t('Antal elementer'),
            t('- Alle -'),
            t('Forskydning'),
            t('« første'),
            t('‹ forrige'),
            t('næste ›'),
            t('sidste »'),
            t('flag_best_answer'),
            t('Afstemningsresultater'),
            t('Flagtidspunkt'),
            t('Bedste svar først'),
            t('Nyeste svar først'),
            t('Alle'),
    );
  $export['answers_to_a_question_myassist_'] = $view;

  return $export;
}
