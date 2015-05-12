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

  // Exported menu link: main-menu_categories:categories
  $menu_links['main-menu_categories:categories'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'categories',
    'router_path' => 'categories',
    'link_title' => 'Categories',
    'options' => array(
      'identifier' => 'main-menu_categories:categories',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: main-menu_hjem:<front>
  $menu_links['main-menu_hjem:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Hjem',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_hjem:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_questions:questions
  $menu_links['main-menu_questions:questions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'questions',
    'router_path' => 'questions',
    'link_title' => 'Questions',
    'options' => array(
      'identifier' => 'main-menu_questions:questions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: main-menu_stil-et-sprgsml:node/add/answers-question
  $menu_links['main-menu_stil-et-sprgsml:node/add/answers-question'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/answers-question',
    'router_path' => 'node/add/answers-question',
    'link_title' => 'Stil et spørgsmål',
    'options' => array(
      'attributes' => array(
        'title' => 'Stil et spørgsmål',
      ),
      'identifier' => 'main-menu_stil-et-sprgsml:node/add/answers-question',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: navigation_add-content:node/add
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_article:node/add/article
  $menu_links['navigation_article:node/add/article'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/article',
    'router_path' => 'node/add/article',
    'link_title' => 'Article',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
      ),
      'identifier' => 'navigation_article:node/add/article',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'navigation_tilfj-indhold:node/add',
  );
  // Exported menu link: navigation_basic-page:node/add/page
  $menu_links['navigation_basic-page:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Basic page',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
      ),
      'identifier' => 'navigation_basic-page:node/add/page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'navigation_tilfj-indhold:node/add',
  );
  // Exported menu link: navigation_compose-tips:filter/tips
  $menu_links['navigation_compose-tips:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'identifier' => 'navigation_compose-tips:filter/tips',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_leaderboard:achievements/leaderboard
  $menu_links['navigation_leaderboard:achievements/leaderboard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'achievements/leaderboard',
    'router_path' => 'achievements/leaderboard',
    'link_title' => 'Leaderboard',
    'options' => array(
      'attributes' => array(
        'title' => 'View the site-wide achievements leaderboard.',
      ),
      'identifier' => 'navigation_leaderboard:achievements/leaderboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_question:node/add/answers-question
  $menu_links['navigation_question:node/add/answers-question'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/answers-question',
    'router_path' => 'node/add/answers-question',
    'link_title' => 'Question',
    'options' => array(
      'attributes' => array(
        'title' => 'A question which can be answered by other users.',
      ),
      'identifier' => 'navigation_question:node/add/answers-question',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'navigation_tilfj-indhold:node/add',
  );
  // Exported menu link: navigation_search:search
  $menu_links['navigation_search:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'identifier' => 'navigation_search:search',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: navigation_users-by-points:userpoints
  $menu_links['navigation_users-by-points:userpoints'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'userpoints',
    'router_path' => 'userpoints',
    'link_title' => 'Users by !points',
    'options' => array(
      'identifier' => 'navigation_users-by-points:userpoints',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
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
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_brugerkonto:user
  $menu_links['user-menu_brugerkonto:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Brugerkonto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'user-menu_brugerkonto:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
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
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
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
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
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
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
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
    'weight' => -42,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_redigr-profil:user/edit
  $menu_links['user-menu_redigr-profil:user/edit'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/edit',
    'router_path' => 'user/edit',
    'link_title' => 'Redigér profil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'user-menu_redigr-profil:user/edit',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_view-profile:user
  $menu_links['user-menu_view-profile:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'View profile',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_view-profile:user',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: user-menu_vis-profil:user
  $menu_links['user-menu_vis-profil:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Vis profil',
    'options' => array(
      'attributes' => array(
        'title' => 'Vis brugerprofilen',
      ),
      'alter' => TRUE,
      'identifier' => 'user-menu_vis-profil:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'da',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Achievements');
  t('Add content');
  t('Article');
  t('Basic page');
  t('Brugerkonto');
  t('Categories');
  t('Compose tips');
  t('Edit Profile');
  t('Hjem');
  t('Home');
  t('Leaderboard');
  t('Log out');
  t('My !points');
  t('Points');
  t('Question');
  t('Questions');
  t('Redigér profil');
  t('Search');
  t('Stil et spørgsmål');
  t('User account');
  t('Users by !points');
  t('View profile');
  t('Vis profil');


  return $menu_links;
}
