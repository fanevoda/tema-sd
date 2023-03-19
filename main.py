import plotly.express as px

introSort = [0, 0, 0, 0, 0, 0.000, 0.000, 0.002, 0.014, 0.031, 0.181, 0.388,  2.145]
quickSort = [0, 0, 0, 0, 0, 0.001, 0.000, 0.005, 0.011, 0.066, 0.152, 0.853, 1.703]
shellSort = [0, 0, 0, 0, 0, 0.000, 0.001, 0.007, 0.018, 0.012,  0.288, 1.969, 4.575]
mergeSort = [0, 0, 0, 0, 0, 0.001, 0.002, 0.014, 0.030, 0.015, 0.336, 1.843, 3.622]
radixSort = [0, 0, 0, 0, 0, 0.003, 0.001, 0.007, 0.014, 0.08, 0.182, 0.906, 1.894]

fig = px.line(x=['10^1','10^1 -> 10^2','10^2','10^2->10^3', '10^3','10^3->10^4', '10^4','10^4->1e5', '10^5', '10^5-10^6', '10^6', '10^6-10^7', '10^7'], y=[introSort, quickSort, shellSort, mergeSort, radixSort])
newnames = {'wide_variable_0':'introSort (c++ sort())', 'wide_variable_1': 'quickSort', 'wide_variable_2' : 'shellSort', 'wide_variable_3' : 'mergeSort', 'wide_variable_4': 'radixSort'}
fig.for_each_trace(lambda t: t.update(name = newnames[t.name],
                                      legendgroup = newnames[t.name],
                                      hovertemplate = t.hovertemplate.replace(t.name, newnames[t.name])
                                     )
                  )

fig.update_layout(
    title="Marimea vectorului",
    xaxis_title="",
    yaxis_title="Timp (secunde.ms)",
    legend_title="Algoritmi",
    font=dict(
        size=18,
    )
)
fig.show()