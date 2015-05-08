<?php
/**
 * @file
 * myassist_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function myassist_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access achievements'.
  $permissions['access achievements'] = array(
    'name' => 'access achievements',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'achievements',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer achievements'.
  $permissions['administer achievements'] = array(
    'name' => 'administer achievements',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'achievements',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create answers_question content'.
  $permissions['create answers_question content'] = array(
    'name' => 'create answers_question content',
    'roles' => array(
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'earn achievements'.
  $permissions['earn achievements'] = array(
    'name' => 'earn achievements',
    'roles' => array(
      'administrator' => 'administrator',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'achievements',
  );

  // Exported permission: 'edit any ungeprofil profile'.
  $permissions['edit any ungeprofil profile'] = array(
    'name' => 'edit any ungeprofil profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any voksenprofil profile'.
  $permissions['edit any voksenprofil profile'] = array(
    'name' => 'edit any voksenprofil profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own ungeprofil profile'.
  $permissions['edit own ungeprofil profile'] = array(
    'name' => 'edit own ungeprofil profile',
    'roles' => array(
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own voksenprofil profile'.
  $permissions['edit own voksenprofil profile'] = array(
    'name' => 'edit own voksenprofil profile',
    'roles' => array(
      'administrator' => 'administrator',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'view any ungeprofil profile'.
  $permissions['view any ungeprofil profile'] = array(
    'name' => 'view any ungeprofil profile',
    'roles' => array(
      'administrator' => 'administrator',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any voksenprofil profile'.
  $permissions['view any voksenprofil profile'] = array(
    'name' => 'view any voksenprofil profile',
    'roles' => array(
      'administrator' => 'administrator',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own ungeprofil profile'.
  $permissions['view own ungeprofil profile'] = array(
    'name' => 'view own ungeprofil profile',
    'roles' => array(
      'ung bruger' => 'ung bruger',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own voksenprofil profile'.
  $permissions['view own voksenprofil profile'] = array(
    'name' => 'view own voksenprofil profile',
    'roles' => array(
      'administrator' => 'administrator',
      'chatrådgiver' => 'chatrådgiver',
      'debatrådgiver' => 'debatrådgiver',
      'moderator' => 'moderator',
      'redaktør' => 'redaktør',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
