qs = [...document.getElementsByTagName("tr")]

//unsolved = qs.filter((q) => q.className !== "completed")
difficulty = "Medium"
unsolved = qs.filter((q) => q.className.includes("completed") == false && [...q.getElementsByTagName("b")][0].innerText == difficulty)
console.log(unsolved[0].getElementsByTagName("b")[0])

qToSolve = unsolved[Math.floor(Math.random() * ((unsolved.length + 1)))]
questionLink = qToSolve.getElementsByTagName("a")[0].href
window.open(questionLink, "_blank")

//Get completed questions
qs = [...document.getElementsByTagName("tr")]

unsolved = qs.filter((q) => q.className === "completed")
solvedQs = []
unsolved.forEach((q) => {
    solvedQs.push(q.getElementsByTagName("a")[0].href)
})
console.log(solvedQs)