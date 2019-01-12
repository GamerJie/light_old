# Light lua API
Here is the lua api of light.
## System
using module :
```lua
require("light.system")
```
### data type
```
entity_list     array of entity
```
### golbal functions

## Light
using module :
```lua
require("light")
```
### data type
```
```
### global functions
```lua
function get_world() return world               -- return current world

function create() return entity                 -- create an entity to current world

function destroy(entity)                        -- destroy an entity form current world

function add_component(entity, component)       -- add a component to entity, the component is the file name of 
                                                -- the component json or string (maybe table)
function remove_component(entity, component)    -- remove a component from entity

```
## Json
using module :
```lua
require("json")
```
### data type
```lua
json     json object
    function dump() return json_table           -- return a table for json file
    function to_string() return json_string     -- return string of json object
```
### golbal functions
```lua
function to_json(json)          -- convert json (json string or lua table) to json object
```