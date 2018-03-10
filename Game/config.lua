if system.getInfo("model") == "iPad" then

    application =
    {
            content =
            {
                    width = 320,
                    height = 427,
                    scale = "letterbox",
                    fps = 60,
                    antialias = false
            },

    }

else

    application =
    {
            content =
            {
                    width = 320,
                    height = 480,
                    scale = "letterbox",
                    fps = 60,
                    antialias = false
            },

    }

end

