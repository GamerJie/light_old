# System
## File type
lua
## Formart
```lua
local xxxSystem

function xxxSystem.init()
    -- return register need listen components
	return { some components name }
end

function xxxSystem.update(dt, component_data_list)
    -- do some logic
end

return xxxSystem
```