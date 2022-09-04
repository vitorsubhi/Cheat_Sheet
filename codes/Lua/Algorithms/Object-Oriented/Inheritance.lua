-- Meta class
Rectangle = {
    length = 0,
    width = 0
}

-- Constructor
function Rectangle:new (o,length,width)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    self.length = length or 0
    self.width = width or 0
    return o
end

-- Methods (Gets and Sets)
function Rectangle:setLength(length)
    self.length = length
end

function Rectangle:getLength()
    return self.length
end

function Rectangle:setWidth(width)
    self.width = width
end

function Rectangle:getWidth()
    return self.width
end

function Rectangle:getArea()
    return self.length * self.width;
end

Square = Rectangle:new()

function Square:new (o, side)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    self.length = side or 0
    self.width = side or 0
    return o
end

function Square:isSquare()
    return true
end

-- New Object
r = Rectangle:new(nil,10,20)
q = Square:new(nil, 10)
print (r:getArea())
r:setWidth(50)
print (r:getArea())
print (q:isSquare())