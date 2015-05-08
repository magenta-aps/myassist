<?php
/**
 * @file
 * myassist_user.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function myassist_user_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_achievements:user/achievements
  $menu_links['user-menu_achievements:user/achievements'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/achievements',
    'router_path' => 'user/achievements',
    'link_title' => 'Achievements',
    'options' => array(
      'attributes' => array(
        'title' => 'View my achievements',
      ),
      'identifier' => 'user-menu_achievements:user/achievements',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_edit-profile:user/edit
  $menu_links['user-menu_edit-profile:user/edit'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/edit',
    'router_path' => 'user/edit',
    'link_title' => 'Edit Profile',
    'options' => array(
      'attributes' => array(
        'title' => 'Edit own profile',
      ),
      'identifier' => 'user-menu_edit-profile:user/edit',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-in:user/login
  $menu_links['user-menu_log-in:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'identifier' => 'user-menu_log-in:user/login',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'user-menu_view-profile:user',
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: user-menu_my-points:myuserpoints
  $menu_links['user-menu_my-points:myuserpoints'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'myuserpoints',
    'router_path' => 'myuserpoints',
    'link_title' => 'My !points',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_my-points:myuserpoints',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: user-menu_points:user/points
  $menu_links['user-menu_points:user/points'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/points',
    'router_path' => 'user/points',
    'link_title' => 'Points',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_points:user/points',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Achievements');
  t('Edit Profile');
  t('Log in');
  t('Log out');
  t('My !points');
  t('Points');


  return $menu_links;
}
