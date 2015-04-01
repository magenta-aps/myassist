<?php
/**
 * @file
 * myassist_categories.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function myassist_categories_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-answers_question-field_category'
  $field_instances['node-answers_question-field_category'] = array(
    'bundle' => 'answers_question',
    'default_value' => array(
      0 => array(
        'tid' => 23,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'answers_full_node' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');

  return $field_instances;
}