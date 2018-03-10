local metrics = {}
-- ------------------------------------------------------------
-- Author: Gleb Gumilevsky
-- gleba6a@mail.ru
-- Date: 30.10.2012
-- ------------------------------------------------------------
local screenAspectRatio -- отношение сторон
local screenHeightRip
local screenWidthRip
local orientation

function metrics:init()
    if system.getInfo("model") == "iPad" then
        print("USING IPAD")
        screenAspectRatio = 1024 / 768

        if (display.contentHeight > display.contentWidth) then
            screenAspectRatio = 1 / screenAspectRatio
        end

    else
        screenAspectRatio = (display.contentWidth + 2 * math.abs(display.screenOriginX)) / (display.contentHeight + 2 * math.abs(display.screenOriginY))
    end

    local screenSmallSideRip = 320
    local screenLargeSideRip

    if (display.contentHeight > display.contentWidth) then
        screenLargeSideRip = screenSmallSideRip / screenAspectRatio
        screenHeightRip = screenLargeSideRip
        screenWidthRip = screenSmallSideRip
        orientation = "portrait"
    else
        screenLargeSideRip = screenSmallSideRip * screenAspectRatio
        screenHeightRip = screenSmallSideRip
        screenWidthRip = math.ceil(screenLargeSideRip)
        orientation = "landscape"
    end

    display.contentHeight = screenHeightRip
end

function metrics:getScreenWidthRip()
    return screenWidthRip
end

function metrics:getScreenHeightRip()
    return screenHeightRip
end

return metrics