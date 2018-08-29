x = [433.536 437.770 ; 444.489  135.653; 522.971 22.326];
str = {'select all'; 'select with conditions'; 'select with average'};
bar(x)
set(gca, 'XTickLabel',str, 'XTick',1:numel(str))
%grid on
%grid minor

xlabel('Query Type')
ylabel ('Time (seconds)')
title('Query Times')
legend('Cloud','Edge & Fog')

