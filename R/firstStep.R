library(ggplot2)
library(gcookbook)
diamonds <- diamonds
set.seed(123)
diamonds <- diamonds[sample(nrow(diamonds), 1000),]
install.packages("car")
summary(diamonds)
str(diamonds)
head(diamonds)

ggplot(diamonds) + geom_point(aes(x=carat, y=price, color=color, shape=cut))
ggplot(diamonds) + geom_point(aes(x=carat, y=price, color=color, shape=cut)) + scale_y_log10() + labs(x="kela", y="jiage", title="tu") + theme(text = element_text(family = "Microsoft YaHei"))
ggplot(diamonds) + geom_histogram(aes(x=price, fill=cut), position = "fill")
ggplot(diamonds) + geom_bar(aes(x=clarity, fill=color))
ggplot(diamonds) + geom_density(aes(x=price, fill=cut, color=cut), alpha=0.2)
ggplot(diamonds) + geom_boxplot(aes(x=cut, y=price, fill=color))

names(diamonds)

ggplot(a) + geom_density(aes(x=ID))
names(a) <- c("ID","x1","x2","x3","y1","y2","y3","v1","t1","t2","t3","times1","times2","byte","s1","s2","s3")
ggplot(a) + geom_point(aes(x=x1, y=y1))
ggplot(a) + geom_point(aes(x=x2, y=y1,color=s3))
ggplot(a) + geom_density(aes(x=x2, y=y1,color=s3))