data Clock = Clock { hours :: Int, minutes :: Int }

clock :: Clock -> Clock
clock (Clock h m)
  | m >= 0 && m < 60 = Clock (h `mod` 24) m
  | m >= 60 = clock (Clock (h + (m `div` 60)) (m `mod` 60))
  | otherwise = clock (Clock (h + ((m `div` 60) - 1)) (60 + (m `mod` 60)))

fromHourMin :: Int -> Int -> Clock
fromHourMin h m
  | h >= 0 && h < 24 && m >= 0 && m < 60 = clock (Clock h m)
  | otherwise = fromHourMin (h `mod` 24) (m `mod` 60)

addDelta :: Int -> Int -> Clock -> Clock
addDelta dh dm (Clock h m) = clock (Clock (h + dh) (m + dm))

toString :: Clock -> String
toString (Clock h m) = padZero h ++ ":" ++ padZero m
  where
    padZero n
      | n < 10 = "0" ++ show n
      | otherwise = show n
