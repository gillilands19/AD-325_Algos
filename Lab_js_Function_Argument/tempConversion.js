function fToC(tempInFar) {
  const tempInCelsius = (5/9) * (tempInFar - 32)
  console.log(tempInCelsius);
}

function cToF(tempInCelsius) {
  const tempInFar = tempInCelsius * 9 / 5 + 32;
  console.log(tempInFar);
}

fToC(32);
cToF(0);