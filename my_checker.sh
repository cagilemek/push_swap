#!/bin/bash
args=("$@")
stack=("${args[@]}")

while IFS= read -r op; do
    case $op in
        sa) tmp=${stack[0]}; stack[0]=${stack[1]}; stack[1]=$tmp ;;
        ra) stack=("${stack[@]:1}" "${stack[0]}") ;;
        rra) last=${stack[-1]}; unset 'stack[-1]'; stack=("$last" "${stack[@]}") ;;
        pb) stackb=("${stack[0]}" "${stackb[@]}"); stack=("${stack[@]:1}") ;;
        pa) stack=("${stackb[0]}" "${stack[@]}"); stackb=("${stackb[@]:1}") ;;
        rb) stackb=("${stackb[@]:1}" "${stackb[0]}") ;;
        rrb) last=${stackb[-1]}; unset 'stackb[-1]'; stackb=("$last" "${stackb[@]}") ;;
        sb) tmp=${stackb[0]}; stackb[0]=${stackb[1]}; stackb[1]=$tmp ;;
    esac
done

sorted=1
for ((i=0; i<${#stack[@]}-1; i++)); do
    if [ "${stack[$i]}" -gt "${stack[$((i+1))]}" ]; then
        sorted=0
        break
    fi
done

if [ $sorted -eq 1 ] && [ ${#stackb[@]} -eq 0 ]; then
    echo "OK"
else
    echo "KO"
fi
