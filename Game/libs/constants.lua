local constants = {}
-- ------------------------------------------------------------
-- Author: Gleb Gumilevsky
-- gleba6a@mail.ru
-- Date: 30.10.2012
-- ------------------------------------------------------------

--- ############### SCREEN ##################------
--- DATA IN RIPs
constants.rip_field_left_border = display.screenOriginX
constants.rip_field_right_border = display.screenOriginX + metrics:getScreenWidthRip()
constants.rip_field_top_border = display.screenOriginY
constants.rip_field_bottom_border = metrics:getScreenHeightRip() - math.abs(display.screenOriginY)

constants.rip_field_width = metrics:getScreenWidthRip()
constants.rip_field_height = metrics:getScreenHeightRip()

constants.rip_field_center_x = display.contentCenterX
constants.rip_field_center_y = display.contentCenterY

constants.m_field_width = 15 --meters
constants.rip_to_meter_ratio = constants.rip_field_width / constants.m_field_width

return constants