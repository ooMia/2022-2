
function clickBorder() {
    // border 버튼을 클릭하면
    // id = "mySpan"인 <span> 태그에
    // 2px violet 색 점선 테두리가 생기도록

    let obj = document.getElementsByTagName("span")
    for (let i = 0; i < obj.length; i++) {
        if (obj[i].id == "mySpan")
            obj[i].style.border = "2px dotted violet"
    }

}

function clickP() {
    // p 버튼을 클릭하면
    // 문서에 <p> 태그가 몇 개 있는지
    // alert()를 통해 출력되도록

    let res = document.getElementsByTagName("p").length
    alert("<p> 태그의 개수는 " + res)
}