-- Lua 5.2 or less
function subrange(t, first, last)
    local sub = {}
    for i=first,last do
        sub[#sub + 1] = t[i]
    end
    return sub
end

-- Lua 5.3 or more
function subrange(t, first, last)
    return table.move(t, first, last), 1, {})
end