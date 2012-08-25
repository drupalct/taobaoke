<?php
/**
 * @file
 * Admin file of Taobaoke module.
 */

// Max number of taobaoke blocks.
define('TAOBAOKE_MAX_BLOCK_COUNT', 10);


/**
 * Taobaoke settings page.
 */
function taobaoke_settings_page() {

  // Set page title.
  drupal_set_title(t('Taobaoke Settings'));

  // Get taobaoke settings.
  $settings = taobaoke_settings_get();

  return drupal_get_form("taobaoke_settings_form", $settings);

}


/**
 * Settings form of Taobaoke settings page.
 */
function taobaoke_settings_form($form, &$form_state, $settings) {
  return _taobaoke_settings_form($settings);
}


/**
 * Taobaoke settings form, this form is used for global settings page and block settings page.
 */
function _taobaoke_settings_form($settings) {
  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('API'),
    '#description' => l(t('Get API'), "http://open.taobao.com",
      array("attributes" => array("target" => "_blank"))),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['api']['app_key'] = array(
    '#type' => 'textfield',
    '#title' => 'app_key',
    '#default_value' => $settings['app_key'],
  );

  $form['api']['app_secret'] = array(
    '#type' => 'textfield',
    '#title' => 'app_secret',
    '#default_value' => $settings['app_secret'],
  );

  $form['arguments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taobaoke Settings'),
    '#description' => l(t("API Tool"), "http://my.open.taobao.com/apitools/apiTools.htm",
      array("attributes" => array("target" => "_blank"))),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  /*
  $form['arguments']['fields'] = array(
    '#type' => 'textfield',
    '#title' => 'fields',
    '#default_value' => $settings['fields'],
    '#required' => TRUE,
  );
  */

  $form['arguments']['nick'] = array(
    '#type' => 'textfield',
    '#title' => 'nick',
    '#default_value' => $settings['nick'],
    '#field_suffix' => '*',
  );

  $form['arguments']['pid'] = array(
    '#type' => 'textfield',
    '#title' => 'pid',
    '#default_value' => $settings['pid'],
    '#field_suffix' => '*',
  );

  $form['arguments']['keyword'] = array(
    '#type' => 'textfield',
    '#title' => 'keyword',
    '#default_value' => $settings['keyword'],
    '#field_suffix' => '*',
  );

  $form['arguments']['cid'] = array(
    '#type' => 'textfield',
    '#title' => 'cid',
    '#description' => l(t("API Attribute Tool"), "http://open.taobao.com/api_tool/props/",
      array("attributes" => array("target" => "_blank"))),
    '#default_value' => $settings['cid'],
    '#field_suffix' => '*',
  );

  $form['arguments']['start_price'] = array(
    '#type' => 'textfield',
    '#title' => 'start_price',
    '#default_value' => $settings['start_price'],
  );

  $form['arguments']['end_price'] = array(
    '#type' => 'textfield',
    '#title' => 'end_price',
    '#default_value' => $settings['end_price'],
  );

  $form['arguments']['auto_send'] = array(
    '#type' => 'textfield',
    '#title' => 'auto_send',
    '#default_value' => $settings['auto_send'],
  );

  $form['arguments']['area'] = array(
    '#type' => 'textfield',
    '#title' => 'area',
    '#default_value' => $settings['area'],
  );

  $credits = array(
    '1heart' => '1heart',
    '2heart' => '2heart',
    '3heart' => '3heart',
    '4heart' => '4heart',
    '5heart' => '5heart',
    '1diamond' => '1diamond',
    '2diamond' => '2diamond',
    '3diamond' => '3diamond',
    '4diamond' => '4diamond',
    '5diamond' => '5diamond',
    '1crown' => '1crown',
    '2crown' => '2crown',
    '3crown' => '3crown',
    '4crown' => '4crown',
    '5crown' => '5crown',
    '1goldencrown' => '1goldencrown',
    '2goldencrown' => '2goldencrown',
    '3goldencrown' => '3goldencrown',
    '4goldencrown' => '4goldencrown',
    '5goldencrown' => '5goldencrown',
  );

  $form['arguments']['start_credit'] = array(
    '#type' => 'select',
    '#title' => 'start_credit',
    '#options' => $credits,
    '#default_value' => $settings['start_credit'],
  );

  $form['arguments']['end_credit'] = array(
    '#type' => 'select',
    '#title' => 'end_credit',
    '#options' => $credits,
    '#default_value' => $settings['end_credit'],
  );

  $sort = array(
    'price_desc' => 'price_desc',
    'price_asc' => 'price_asc',
    'credit_desc' => 'credit_desc',
    'commissionRate_desc' => 'commissionRate_desc',
    'commissionRate_asc' => 'commissionRate_asc',
    'commissionNum_desc' => 'commissionNum_desc',
    'commissionNum_asc' => 'commissionNum_asc',
    'commissionValue_desc' => 'commissionValue_desc',
    'commissionValue_asc' => 'commissionValue_asc',
    'delistTime_desc' => 'delistTime_desc',
    'delistTime_asc' => 'delistTime_asc',
  );

  $form['arguments']['sort'] = array(
    '#type' => 'select',
    '#title' => 'sort',
    '#options' => $sort,
    '#default_value' => $settings['sort'],
  );

  $form['arguments']['guarantee'] = array(
    '#type' => 'textfield',
    '#title' => 'guarantee',
    '#default_value' => $settings['guarantee'],
  );

  $form['arguments']['start_commissionRate'] = array(
    '#type' => 'textfield',
    '#title' => 'start_commissionRate',
    '#default_value' => $settings['start_commissionRate'],
  );

  $form['arguments']['end_commissionRate'] = array(
    '#type' => 'textfield',
    '#title' => 'end_commissionRate',
    '#default_value' => $settings['end_commissionRate'],
  );

  $form['arguments']['start_commissionNum'] = array(
    '#type' => 'textfield',
    '#title' => 'start_commissionNum',
    '#default_value' => $settings['start_commissionNum'],
  );

  $form['arguments']['end_commissionNum'] = array(
    '#type' => 'textfield',
    '#title' => 'end_commissionNum',
    '#default_value' => $settings['end_commissionNum'],
  );

  $form['arguments']['start_totalnum'] = array(
    '#type' => 'textfield',
    '#title' => 'start_totalnum',
    '#default_value' => $settings['start_totalnum'],
  );

  $form['arguments']['end_totalnum'] = array(
    '#type' => 'textfield',
    '#title' => 'end_totalnum',
    '#default_value' => $settings['end_totalnum'],
  );

  $form['arguments']['cash_coupon'] = array(
    '#type' => 'textfield',
    '#title' => 'cash_coupon',
    '#default_value' => $settings['cash_coupon'],
  );

  $form['arguments']['vip_card'] = array(
    '#type' => 'textfield',
    '#title' => 'vip_card',
    '#default_value' => $settings['vip_card'],
  );

  $form['arguments']['overseas_item'] = array(
    '#type' => 'textfield',
    '#title' => 'overseas_item',
    '#default_value' => $settings['overseas_item'],
  );

  $form['arguments']['sevendays_return'] = array(
    '#type' => 'textfield',
    '#title' => 'sevendays_return',
    '#default_value' => $settings['sevendays_return'],
  );

  $form['arguments']['real_describe'] = array(
    '#type' => 'textfield',
    '#title' => 'real_describe',
    '#default_value' => $settings['real_describe'],
  );

  $form['arguments']['onemonth_repair'] = array(
    '#type' => 'textfield',
    '#title' => 'onemonth_repair',
    '#default_value' => $settings['onemonth_repair'],
  );

  $form['arguments']['cash_ondelivery'] = array(
    '#type' => 'textfield',
    '#title' => 'cash_ondelivery',
    '#default_value' => $settings['cash_ondelivery'],
  );

  $form['arguments']['mall_item'] = array(
    '#type' => 'textfield',
    '#title' => 'mall_item',
    '#default_value' => $settings['mall_item'],
  );

  $form['arguments']['page_no'] = array(
    '#type' => 'textfield',
    '#title' => 'page_no',
    '#default_value' => $settings['page_no'],
  );

  $form['arguments']['page_size'] = array(
    '#type' => 'textfield',
    '#title' => 'page_size',
    '#default_value' => $settings['page_size'],
  );

  $form['arguments']['outer_code'] = array(
    '#type' => 'textfield',
    '#title' => 'outer_code',
    '#default_value' => $settings['outer_code'],
  );

  $form['arguments']['is_mobile'] = array(
    '#type' => 'textfield',
    '#title' => 'is_mobile',
    '#default_value' => $settings['is_mobile'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    // '#validate' => array('spider_admin_region_form_validate'),
    '#submit' => array('taobaoke_settings_form_submit'),
  );

  return $form;
}


/**
 * Handle settings form submitting.
 */
function taobaoke_settings_form_submit($form, &$form_state) {

  // Get submitted values.
  $settings = $form_state['values'];

  $settings_index = taobaoke_settings_index();

  // Save settings.
  foreach ($settings as $key => $value) {

    // Save settings if it's a taobaoke settings item.
    if (in_array($key, $settings_index)) {
      variable_set('taobaoke_' . $key, $value);
    }

  }

  drupal_set_message(t("Settings are saved."));

  return;
}


/**
 * Taobaoke blocks configure page.
 */
function taobaoke_block_admin_page() {

  $block_count = variable_get('taobaoke_block_count', 1);

  return drupal_get_form('taobaoke_block_admin_form', $block_count);
}


/**
 * Taobaoke block settings form.
 */
function taobaoke_block_admin_form($form, &$form_state, $block_count) {
  $form = array();

  $form['count'] = array(
    '#type' => 'textfield',
    '#title' => t('Block Count'),
    '#description' => t('How many taobaoke block would you like to create. Range:1-!max_count.',
      array('!max_count' => check_plain(TAOBAOKE_MAX_BLOCK_COUNT))),
    '#size' => 2,
    '#maxlength' => 2,
    '#default_value' => $block_count,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('taobaoke_block_admin_form_submit'),
  );

  return $form;
}


/**
 * Handle block settings form submitting.
 */
function taobaoke_block_admin_form_submit($form, &$form_state) {

  $block_count = $form_state['values']['count'];

  if (is_numeric($block_count) && $block_count >= 1
    && $block_count <= TAOBAOKE_MAX_BLOCK_COUNT) {
    $block_count = max(1, min($block_count, TAOBAOKE_MAX_BLOCK_COUNT));
  }
  else {
    drupal_set_message(t('The value of block count must between 1 and %max_count',
      array('%max_count' => TAOBAOKE_MAX_BLOCK_COUNT)));

    $block_count = variable_get('taobaoke_block_count', 1);
  }

  variable_set('taobaoke_block_count', $block_count);
  drupal_set_message(t('Configuration are saved.'));

}
