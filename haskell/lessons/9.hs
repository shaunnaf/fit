data Color = Red | Green | Blue

rgb :: Color -> [Double]
rgb Red = [1,0,0]
rgb Green = [0,1,0]
rgb Blue = [0,0,1]

data DayOfWeek = Mon|Tue|Wed|Thu|Fri|Sat|Sun

isWeekend ::DayOfWeek -> Bool
isWeekend Mon = False
isWeekend Tue = False
isWeekend Wed = False
isWeekend Thu = False
isWeekend Fri = False
isWeekend Sat = True
isWeekend Sun = True

data PointD = PointD Double Double
                    deriving Show

distanceToOrigin :: PointD -> Double
distanceToOrigin (PointD x y) = sqrt (x^2 + y^2)

distance :: PointD -> PointD -> Double
distance = 

data Shape = Circle Double | Rectangle Double Double

area :: Shape -> Double
area (Circle r) = pi*r^2
area (Rectangle a b) = a*b


