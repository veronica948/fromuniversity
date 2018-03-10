-- ------------------------------------------------------------
-- Author: Gleb Gumilevsky
-- gleba6a@mail.ru
-- Date: 30.10.2012
-- ------------------------------------------------------------
--- MEMBERS
local scene = storyboard.newScene()
local localGroup
local constants = constants
-- FUNCTIONS
local createBackground

function scene:createScene(event)
    localGroup = self.view
    createBackground()

end

function scene:destroyScene(event)
end

scene:addEventListener("createScene")
scene:addEventListener("destroyScene")

 createBackground = function()
    local sky = display.newRect(localGroup, constants.rip_field_left_border, constants.rip_field_top_border,
        constants.rip_field_width, constants.rip_field_height)
    sky:setFillColor(0, 0, 230)

    local ground = display.newRect(localGroup, constants.rip_field_left_border, constants.rip_field_bottom_border - constants.rip_field_height / 4,
        constants.rip_field_width, constants.rip_field_height / 4)
    ground:setFillColor(0, 255, 0)
    for i=constants.rip_field_left_border,constants.rip_field_right_border do
        local j=40*math.sin(i/60)
        local way = display.newRect(i,constants.rip_field_height/2+j,1,1)

    end
    local textTime = display.newText( "Time", constants.rip_field_right_border-100, constants.rip_field_top_border+10, "Arial", 20)
    local textPoints= display.newText( "Points", constants.rip_field_right_border-100, constants.rip_field_top_border+35, "Arial", 20)
    local moon = display.newCircle(localGroup, 30, 30, 15)

    --localGroup.alpha = 0.5
end
local vagon = display.newImage( "vagon1.png" )
vagon.weight=100
vagon:setReferencePoint(display.BottomCenterReferencePoint)
vagon.x = constants.rip_field_left_border+40;
vagon.rotation = 0

local pushka = display.newImage( "pushka.png" )
pushka:setReferencePoint(display.BottomCenterReferencePoint)
pushka.height=70
pushka.x = constants.rip_field_width/2
pushka.y = constants.rip_field_height-20
local circle = display.newCircle( constants.rip_field_width/2,constants.rip_field_height-80 , 10)

--rotation
 local function rotate (event)
    local  t = event.target
    if event.phase == "moved" then

        t.x = event.x
        t.y = event.y

        pushka.rotation =math.atan((t.x-constants.rip_field_width/2)/(constants.rip_field_height-20-t.y))*180/3.14


    end
         if event.phase == "ended" then
        pushka.rotation=0
        circle.x= constants.rip_field_width/2  circle.y=constants.rip_field_height-80
        end
    end

circle:addEventListener( "touch", rotate )

--points
local point=0;
local textX = display.newText( point, constants.rip_field_right_border-30, constants.rip_field_top_border+35, "Arial", 20)

--timer

local timeDelay = 900		-- Timer value
local  timerID	-- forward references
local started = true
local text = ""
local dY = 20	-- starting location
text = display.newText( "0", constants.rip_field_right_border-30, constants.rip_field_top_border+10, "Arial", 20 )

function text:timer( event )

    local count = event.count

    --print( "Table listener called " .. count .. " time(s)" )
    self.text = count

    if count >= 60 then
        timer.cancel( event.source ) -- after the 20th iteration, cancel timer
        local textEnd
        --textEnd= display.newText( "Game over", constants.rip_field_center_x-100 , constants.rip_field_center_y-50 , "Arial", 50)
    end
end
-- Register to call t's timer method 50 times
timerID = timer.performWithDelay( timeDelay, text, 60 )


print( "timerID = " .. tostring( timerID ) )

--moving
local myListener = function( event )
    vagon.x = vagon.x + 1
    vagon.y = 40*math.sin(vagon.x/60)+160
    if(vagon.x==constants.rip_field_right_border+50) then vagon.x=constants.rip_field_left_border-50;
    end
    vagon.rotation=math.atan(40*math.cos(vagon.x/60)/60)*180/3.14
end

Runtime:addEventListener( "enterFrame", myListener )

return scene

