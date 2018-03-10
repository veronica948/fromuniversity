-- ------------------------------------------------------------
-- Author: Gleb Gumilevsky
-- gleba6a@mail.ru
-- Date: 30.10.2012
-- ------------------------------------------------------------
--- FUNCTIONS
local main
local init


main = function()
    init()
    storyboard.gotoScene("scenes.scene_gameplay")
    --return true


end

init = function()
    display.setStatusBar( display.HiddenStatusBar )
    --- storyboard
    storyboard = require("storyboard")
    --- enabel to clean current scene after going to another one
    storyboard.purgeOnSceneChange = true

    --- metrics
    metrics = require("libs.metrics")
    metrics:init()

    constants = require("libs.constants")
    local physics = require("physics")
    physics.start()
    physics.setScale( 60 )
    physics.setGravity( 0, 0 )
    physics.setDrawMode('hybrid')
end

main()
