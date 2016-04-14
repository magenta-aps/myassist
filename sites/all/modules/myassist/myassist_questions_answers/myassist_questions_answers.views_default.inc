<?php
/**
 * @file
 * myassist_categories.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function myassist_questions_answers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'frontpage';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
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
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* Sort criterion: Indhold: Klæbrig */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Oprettelsesdato';
  /* Sort criterion: Assists: Answers count */
  $handler->display->display_options['sorts']['answers_count']['id'] = 'answers_count';
  $handler->display->display_options['sorts']['answers_count']['table'] = 'answers';
  $handler->display->display_options['sorts']['answers_count']['field'] = 'answers_count';
  $handler->display->display_options['sorts']['answers_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['answers_count']['expose']['label'] = 'Antal assists';
  /* Sort criterion: latest_activity */
  $handler->display->display_options['sorts']['latest_activity_1']['id'] = 'latest_activity_1';
  $handler->display->display_options['sorts']['latest_activity_1']['table'] = 'answers';
  $handler->display->display_options['sorts']['latest_activity_1']['field'] = 'latest_activity';
  $handler->display->display_options['sorts']['latest_activity_1']['ui_name'] = 'latest_activity';
  $handler->display->display_options['sorts']['latest_activity_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['latest_activity_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['latest_activity_1']['expose']['label'] = 'Latest activity';
  /* Filter criterion: Indhold: Forfremmet til forside */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'answers_question' => 'answers_question',
  );
  /* Filter criterion: Has assist */
  $handler->display->display_options['filters']['question_locks_value']['id'] = 'question_locks_value';
  $handler->display->display_options['filters']['question_locks_value']['table'] = 'field_data_question_locks';
  $handler->display->display_options['filters']['question_locks_value']['field'] = 'question_locks_value';
  $handler->display->display_options['filters']['question_locks_value']['ui_name'] = 'Has assist';
  $handler->display->display_options['filters']['question_locks_value']['value'] = array(
    'answers_best_answer' => 'answers_best_answer',
    'myassist_questions_answers' => 'myassist_questions_answers',
  );
  $handler->display->display_options['filters']['question_locks_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['question_locks_value']['expose']['operator_id'] = 'question_locks_value_op';
  $handler->display->display_options['filters']['question_locks_value']['expose']['label'] = 'Locked (question_locks)';
  $handler->display->display_options['filters']['question_locks_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['question_locks_value']['expose']['operator'] = 'question_locks_value_op';
  $handler->display->display_options['filters']['question_locks_value']['expose']['identifier'] = 'question_locks_value';
  $handler->display->display_options['filters']['question_locks_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    9 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['question_locks_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['question_locks_value']['group_info']['label'] = 'Locked (question_locks)';
  $handler->display->display_options['filters']['question_locks_value']['group_info']['identifier'] = 'question_locks_value';
  $handler->display->display_options['filters']['question_locks_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Har assist',
      'operator' => 'or',
      'value' => array(
        'answers_best_answer' => 'answers_best_answer',
        'myassist_questions_answers' => 'myassist_questions_answers',
      ),
    ),
    2 => array(
      'title' => 'Mangler assist',
      'operator' => 'not',
      'value' => array(
        'answers_best_answer' => 'answers_best_answer',
        'myassist_questions_answers' => 'myassist_questions_answers',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'frontpage';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front page feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';
  $translatables['frontpage'] = array(
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
    t('Oprettelsesdato'),
    t('Antal assists'),
    t('Latest activity'),
    t('Locked (question_locks)'),
    t('Page'),
    t('Feed'),
    t('Front page feed'),
  );

  $export['categories'] = $view;

  return $export;
}
