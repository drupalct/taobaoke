<?php

/**
 * @file
 * Default taobaoke item detail template file
 */
?>

<div id="taobaoke_item_area">

  <h1 class="title"><?php print $taobaoke_item['title']; ?></h1>

  <div class="item_box">

    <div class="pic">
      <img src="<?php print $taobaoke_item['pic_url']; ?>" />
    </div>

    <div class="info">

      <div class="price">
        <span><?php print t("Price"); ?>:</span>
        <strong><?php print $taobaoke_item['price']; ?></strong>元
      </div>

      <div class="fee">
        <span><?php print t("Express Fee"); ?>:</span>

        <?php if ($taobaoke_item['freight_payer'] == "buyer"): ?>

          <?php print t('EMS'); ?>
          <em><?php print $taobaoke_item['ems_fee']; ?></em>元
          <?php print t('Express'); ?>
          <em><?php print $taobaoke_item['express_fee']; ?></em>元

        <?php elseif ($taobaoke_item['freight_payer'] == "seller"): ?>
          <?php print t('Buyer'); ?>
        <?php endif; ?>
      </div>

      <div class="place">
        <span><?php print t("Place"); ?>:</span>
        <?php print $taobaoke_item['city'] . " " . $taobaoke_item['state']; ?>
      </div>

      <div class="num">
        <span><?php print t("Num"); ?>:</span>
        <strong><?php print $taobaoke_item['num'] ?></strong>件
      </div>

      <div class="stuff_status">
        <span><?php print t("Stuff Status"); ?>:</span>
        <?php print t($taobaoke_item['stuff_status']); ?>
      </div>

      <div class="approve_status">
        <span><?php print t("Approve Status"); ?>:</span>
        <?php print t($taobaoke_item['approve_status']); ?>
      </div>

      <div class="buy">
        <?php print l(t('Go to Taobao'), 'shop/item/' . $taobaoke_item['num_iid'] . '/go', array('attributes' => array('target' => '_blank'))); ?>
      </div>

      <div class="fav">
        <?php print l(t('Seller shop'), 'shop/shop/' . $taobaoke_item['num_iid'] . '/go', array('attributes' => array('target' => '_blank'))); ?>
      </div>

    </div> <!-- // .info -->

  </div> <!-- // .item_box -->

  <div class="item_desc">
    <?php print $taobaoke_item['desc']; ?>
  </div>

</div> <!-- // #taobaoke_item_area -->