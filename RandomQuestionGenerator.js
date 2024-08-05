qs = [...document.getElementsByTagName("tr")]

//unsolved = qs.filter((q) => q.className !== "completed")
unsolved = qs.filter((q) => q.className.includes("completed") == false)

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