<?php
/**
 * @file
 * addfullajax
 * admin things
 */


/**
 * Form function, called by drupal_get_form()
 */
function addfullajax_admin_form($form, &$form_state) {

  $form['addfullajax_cssid'] = array(
    '#type'  =>  'textfield',
    '#title'  =>  t('CSS id for content block'),
    '#default_value'  =>  variable_get('addfullajax_cssid', 'forajax'),
    '#size'  =>  12,
    '#maxlength'  =>  255,
    '#description'  =>  t('CSS id for content block where shown contents'),
    '#required'  =>  TRUE,
  );

  // themes configuration
  $form['addfullajax_themes'] = array(
    '#type'  =>  'fieldset',
    '#title'  =>  t('Themes configs'),
    '#collapsible'  =>  FALSE,
    '#collapsed'  =>  FALSE,
    'theme_regions'  =>  array(
      '#type'  =>  'fieldset',
      '#title'  =>  t('Render regions of a theme'),
      '#collapsible'  =>  TRUE,
      '#collapsed'  =>  TRUE,
      '#weight' => 30,
    ),
  );
  $themes = list_themes();
  $active_themes = array();
  foreach ($themes as $name => $them) {
    if ($them->status) {
      $active_themes[$name] = $name;

      $form['addfullajax_themes']['addfullajax_themes_' . $name . '_main_region'] = array(
        '#type'   =>  'select',
        '#title'  =>  t('Main region for @theme', array('@theme' => $name)),
        '#description'  =>  t('Select region that used for display main content.'),
        '#options' => $themes[$name]->info['regions'],
        '#default_value'  =>  variable_get('addfullajax_themes_' . $name . '_main_region', 'content'),
      );

      $form['addfullajax_themes']['theme_regions']['addfullajax_themes_' . $name . '_regions'] = array(
        '#type'   =>  'checkboxes',
        '#title'  =>  t('For @theme', array('@theme' => $name)),
        '#description'  =>  t('Select regions that will be rendered for each FullAjax answer.'),
        '#options'  =>  $themes[$name]->info['regions'],
        '#default_value'  =>  variable_get('addfullajax_themes_' . $name . '_regions', array('content')),
      );
    }
  }
  $form['addfullajax_themes']['addfullajax_themes_themes'] = array(
    '#type'  =>  'fieldset',
    '#title'  =>  t('Disable for template'),
    '#collapsible'  =>  TRUE,
    '#collapsed'  =>  TRUE,
    '#weight' => 31,
    'addfullajax_themes_disabled'  =>  array(
      '#type'   =>  'checkboxes',
      '#title'  =>  t('Disable for themes'),
      '#description'  =>  t('Disable for theme. FullAjax will not connect for these themes.'),
      '#options'  =>  $active_themes,
      '#default_value'  =>  variable_get('addfullajax_themes_disabled', array('seven')),
    ),
  );

  // base configuration
  $form['addfullajax_use_html5'] = array(
    '#type'  =>  'checkbox',
    '#title'  =>  t('HTML5 History API'),
    '#description'  =>  t('Enable using HTML5 History API'),
    '#default_value'  =>  variable_get('addfullajax_use_html5', 1),
  );
  $form['addfullajax_checkmenuit'] = array(
    '#type'  =>  'checkbox',
    '#title'  =>  t('Auto check active menu item'),
    '#description'  =>  t('Enable auto check the active menu item'),
    '#default_value'  =>  variable_get('addfullajax_checkmenuit', 1),
  );
  $form['addfullajax_usr_cache'] = array(
    '#type'   =>  'checkbox',
    '#title'  =>  t('User-side Cache'),
    '#description'  =>  t('Enable Cache on user-side'),
    '#default_value'  =>  variable_get('addfullajax_usr_cache', 1),
  );
  $form['addfullajax_useGA'] = array(
    '#type'   =>  'checkbox',
    '#title'  =>  t('I use Google Analytics'),
    '#description'  =>  t('Check if you use Google Analytics'),
    '#default_value'  =>  variable_get('addfullajax_useGA', 0),
  );
  $form['addfullajax_data'] = array(
    '#type'  =>  'textarea',
    '#title'  =>  t('FullAjax configuration'),
    '#default_value'  =>  variable_get('addfullajax_data', _addfullajax_def_values('conf_base')),
    '#cols'  =>  10,
    '#rows'  =>  12,
    '#description'  =>  t('JavaScript code for FullAjax configuration'),
    '#required'  =>  TRUE,
  );
  $form['addfullajax_animation'] = array(
    '#type'  =>  'textarea',
    '#title'  =>  t('Code for AJAX animation'),
    '#default_value'  =>  variable_get('addfullajax_animation', _addfullajax_def_values('conf_anim')),
    '#cols'  =>  10,
    '#rows'  =>  12,
    '#description'  =>  t('JavaScript code for AJAX animation'),
    '#required'  =>  FALSE,
  );

  // couple things for debug
  $form['addfullajax_debug'] = array(
    '#type'  =>  'checkboxes',
    '#title'  =>  t('For Debug'),
    '#default_value'  =>  variable_get('addfullajax_debug', array()),
    '#options'  =>  array(
      'debug_ajax'  => t('Debug Ajax request'),
      'debug_script'  => t('Debug script loading'),
      'debug_link'  =>  t('Debug link loading'),
      'debug_style'  =>  t('Debug style loading'),
    ),
    '#description'  =>  t('Use for debug'),
    '#prefix'  =>  '<hr />',
  );

  return system_settings_form($form);
}